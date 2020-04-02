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
        string[] separator = { "!?&№~" };        //разделитель записей в файле
        public bool CheckToCreateBook = false; //переменная для проверки на добавление или редактирование книг
        public bool CheckToCreateJournal = false; //переменная для проверки на добавление или редактирование журналов


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
                

        private void button2_Click(object sender, EventArgs e) //запуск формы для добавления книги
        {
            book book = new book(CheckToCreateBook);
            book.Owner = this;
            book.Text = "Добавление книги";
            book.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e) //запуск формы для добавления журнала
        {
            journal journal = new journal(CheckToCreateJournal);
            journal.Owner = this;
            journal.Text = "Добавление журнала";
            journal.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e) //запись значений в файл
        {
            Stream myStream;

            if ((dataGridView1.RowCount == 0) & (dataGridView2.RowCount == 0)) //проверка на пустоту записей
            {
                MessageBox.Show("Нет книг и журналов для сохранения!");
            }
            else
            {
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
                                    sf.Write(dataGridView1.Rows[i].Cells[j].Value.ToString() + separator[0]);
                                }
                                sf.WriteLine();
                            }
                            for (int i = 0; i < dataGridView2.RowCount; i++)
                            {
                                for (int j = 0; j < dataGridView2.ColumnCount; j++)
                                {
                                    sf.Write(dataGridView2.Rows[i].Cells[j].Value.ToString() + separator[0]);
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
                            MessageBox.Show("Файл успешно сохранен");
                        }

                        myStream.Close();
                    }
                }
            }
        }

        private void button5_Click(object sender, EventArgs e) //удаление книги
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

        private void button8_Click(object sender, EventArgs e) //удаление журнала
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

        private void button6_Click(object sender, EventArgs e) //запуск формы для редактирования книги
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
                book.Text = "Изменение книги";
                book.ShowDialog();
            }
            catch
            {
                MessageBox.Show("Нет книг для редактирования!");
            }
        }        

        private void button7_Click(object sender, EventArgs e) //запуск формы для редактирования книги
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
                journal.Text = "Изменение журнала";
                journal.ShowDialog();
            }
            catch
            {
                MessageBox.Show("Нет журналов для редактирования!");
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e) // подгонка размеров при изменении размеров формы
        {
            dataGridView1.Width = this.Width / 2 - 35;
            dataGridView2.Width = this.Width / 2 - 25;
            dataGridView2.Left = this.Width / 2 - 3;
            button1.Left = this.Width / 2 - 165;
            button3.Left = this.Width / 2 + 18;
        }  

        
    }
}
