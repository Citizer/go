using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsAppLR3
{
    public partial class Form1 : Form
    {
        string filePath;
        int flag = 1;
        public Form1(bool hasClParams, string nameOfFile)
        {
            InitializeComponent();
			if (hasClParams)            //Если в командной строке было введено название файла
			{
				filePath = nameOfFile;
				build_diagram();
			}

		}

        private void Button1_Click(object sender, EventArgs e)
        {
			build_diagram();

		}


		//Построение диаграммы
		private void build_diagram()
		{
			if (flag == 1)
			{
				flag = 0;
				try
				{
					using (StreamReader sr = new StreamReader(filePath))
					//Пусть до файла с исходными данными (преобразованными) 
					{
						int RowsCount;
						int.TryParse(sr.ReadLine(), out RowsCount);

						//Создаём таблицу
						for (int i = 0; i <= 80; i++)
						{
							dataGridView1.Columns.Add("T" + (i + 1).ToString(), (i + 1).ToString());
							dataGridView1.Columns[i].Width = 25;
						}

						for (int i = 0; i < RowsCount; i++)
						{
							string[] row = sr.ReadLine().Split(' ');

							int[] numbers = new int[6];
							//Заполняем таблицу
							for (int j = 0; j < 6; j++)
							{
								int.TryParse(row[j], out numbers[j]);
								dataGridView1.Rows.Add();
								dataGridView1.Rows[i].HeaderCell.Value = numbers[0].ToString() + " -> " + numbers[1].ToString();
								for (int k = numbers[2]; k < numbers[3]; k++) dataGridView1.Rows[i].Cells[k].Style.BackColor = Color.Gray;
								for (int k = numbers[3]; k < numbers[4]; k++) dataGridView1.Rows[i].Cells[k].Style.BackColor = Color.Green;
								for (int k = numbers[4]; k < numbers[5]; k++) dataGridView1.Rows[i].Cells[k].Style.BackColor = Color.DarkSlateGray;


							}
						}
					}
				}
				catch (IOException ex)
				{
					MessageBox.Show(ex.Message);
				}
				catch (FormatException fe)
				{
					MessageBox.Show(fe.Message);
				}
			}
		}

        private void DataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                filePath = ofd.FileName;
            }
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            flag = 1;
        }
    }
}
