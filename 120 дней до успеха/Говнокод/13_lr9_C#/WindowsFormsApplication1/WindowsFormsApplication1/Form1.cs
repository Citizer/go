using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        string[] separator = { "!?&№~" };        
        public bool CheckToCreateBook = false;
        public bool CheckToCreateJournal = false;


        public Form1()
        {
            InitializeComponent();         
            
        }

        private void button1_Click(object sender, EventArgs e)
        {            
            //сначала выбор файла
            OpenFileDialog of = new OpenFileDialog();
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                var sr = new StreamReader(openFileDialog1.FileName);

                // считывание в таблицу
                try
                {
                    int RowsCount;
                    int.TryParse(sr.ReadLine(), out RowsCount); //считываем число строк
                    //string[] separator = { "!?&№~" };
                    for (int i = 0; i < RowsCount; i++)
                    {
                        string[] row = sr.ReadLine().Split(separator, StringSplitOptions.RemoveEmptyEntries);

                        if (row[2] == "book")
                        {
                            dataGridView1.Rows.Add(row[0], row[1], row[2], row[3], row[4], row[5]);
                        }
                        if (row[2] == "journal")
                        {
                            dataGridView2.Rows.Add(row[0], row[1], row[2], row[3], row[4], row[5]);
                        }
                    }
                }
                catch
                {
                    MessageBox.Show("Что-то пошло не так((");
                }
            }                  
        }     
                

        private void button2_Click(object sender, EventArgs e)
        {
            book book = new book(CheckToCreateBook);
            book.Owner = this;
            book.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            journal journal = new journal(CheckToCreateJournal);
            journal.Owner = this;
            journal.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Stream myStream;            

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog1.OpenFile()) != null)
                {
                    StreamWriter sf = new StreamWriter(myStream);
                    try
                    {
                        sf.Write(dataGridView1.RowCount + dataGridView2.RowCount);
                        sf.WriteLine();
                        for (int i = 0; i < dataGridView1.RowCount; i++)
                        {
                            for (int j = 0; j < dataGridView1.ColumnCount; j++)
                            {
                                sf.Write(dataGridView1.Rows[i].Cells[j].Value.ToString() + "!?&№~");
                            }
                            sf.WriteLine();                            
                        }
                        for (int i = 0; i < dataGridView2.RowCount; i++)
                        {
                            for (int j = 0; j < dataGridView2.ColumnCount; j++)
                            {
                                sf.Write(dataGridView2.Rows[i].Cells[j].Value.ToString() + "!?&№~");
                            }
                            sf.WriteLine();
                        }

                    }
                    catch
                    {
                        MessageBox.Show("Что-то пошло не так((");
                    }
                    finally
                    {
                        sf.Close();
                    }

                    myStream.Close();
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (dataGridView1.RowCount > 0)
            {

                try
                {
                    if (MessageBox.Show("Удалить запись о книге?", "Удаление", MessageBoxButtons.OKCancel,
                    MessageBoxIcon.Warning, MessageBoxDefaultButton.Button2) == DialogResult.OK)
                    {

                        int delete = dataGridView1.SelectedCells[0].RowIndex;
                        dataGridView1.Rows.RemoveAt(delete);
                    }
                }
                catch
                {
                    MessageBox.Show("Нельзя удалить запись о книге, т.к. она не выбрана");
                }
            }
            else
            {
                MessageBox.Show("Нет книг для удаления!");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (dataGridView2.RowCount > 0)
            {
                try
                {
                    if (MessageBox.Show("Удалить запись о журнале?", "Удаление", MessageBoxButtons.OKCancel,
                    MessageBoxIcon.Warning, MessageBoxDefaultButton.Button2) == DialogResult.OK)
                    {

                        int delete = dataGridView2.SelectedCells[0].RowIndex;
                        dataGridView2.Rows.RemoveAt(delete);
                    }
                }
                catch
                {
                    MessageBox.Show("Нельзя удалить запись о журнале, т.к. она не выбрана");
                }
            }
            else
            {
                MessageBox.Show("Нет журналов для удаления!");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            try
            {

                book book = new book(CheckToCreateBook);
                book.Owner = this;
                book.textBox1.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
                book.textBox2.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
                DateTime newDateTime;
                string s;
                s = "30.03." + dataGridView1.CurrentRow.Cells[3].Value.ToString() + " 20:28:46"; //дописываем для правильного формата любую дату и время
                DateTime.TryParse(s, out newDateTime);
                book.dateTimePicker1.Value = newDateTime;
                book.textBox4.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
                book.textBox5.Text = dataGridView1.CurrentRow.Cells[5].Value.ToString();
                CheckToCreateBook = true; //     переводим в режим редактирования       
                book.ShowDialog();
            }
            catch
            {
                MessageBox.Show("Нет записей для редактирования!");
            }
        }

        private void Form1_Activated(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            try
            {

                journal journal = new journal(CheckToCreateJournal);
                journal.Owner = this;
                journal.textBox1.Text = dataGridView2.CurrentRow.Cells[0].Value.ToString();
                journal.textBox2.Text = dataGridView2.CurrentRow.Cells[1].Value.ToString();
                DateTime newDateTime;
                string s;
                s = "30.03." + dataGridView2.CurrentRow.Cells[3].Value.ToString() + " 20:28:46"; //дописываем для правильного формата любую дату и время
                DateTime.TryParse(s, out newDateTime);
                journal.dateTimePicker1.Value = newDateTime;
                journal.textBox4.Text = dataGridView2.CurrentRow.Cells[4].Value.ToString();
                journal.textBox5.Text = dataGridView2.CurrentRow.Cells[5].Value.ToString();
                CheckToCreateJournal = true; //     переводим в режим редактирования 
                journal.ShowDialog();
            }
            catch
            {
                MessageBox.Show("Нет записей для редактирования!");
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {

        }

        private void Form1_SizeChanged_1(object sender, EventArgs e)
        {
            dataGridView1.Width = this.Width / 2 - 35;
            dataGridView2.Width = this.Width / 2 - 25;
            dataGridView2.Left = this.Width / 2 - 3;
            button1.Left = this.Width / 2 - 165;
            button3.Left = this.Width / 2 + 18;
            
        }

        
    }
}
