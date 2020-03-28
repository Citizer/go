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
                        string[] row = sr.ReadLine().Split(' ');

                        if (row[2] == "book")
                        {
                            dataGridView1.Rows.Add(row[0], row[1], row[2], row[3], row[4], row[5]);
                        }
                        else
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
            

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void dataGridView1_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
        {
              
        }

        private void button2_Click(object sender, EventArgs e)
        {
            book book = new book();
            book.Owner = this;
            book.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            journal journal = new journal();
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
                                sf.Write(dataGridView1.Rows[i].Cells[j].Value.ToString() + " ");
                            }
                            sf.WriteLine();                            
                        }
                        for (int i = 0; i < dataGridView2.RowCount; i++)
                        {
                            for (int j = 0; j < dataGridView2.ColumnCount; j++)
                            {
                                sf.Write(dataGridView2.Rows[i].Cells[j].Value.ToString() + " ");
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
    }
}
