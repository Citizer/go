using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class book : Form
    {
        
        public book()
        {            
            InitializeComponent();            
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.CustomFormat = "yyyy";            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1; //стали владельцем

            //проверка всех textbox на пустоту, если пустой то закрасить красным        
            
            bool someEmpty = false;
            foreach (TextBox textBox in Controls.OfType<TextBox>())
            {
                if (string.IsNullOrEmpty(textBox.Text))
                {
                    someEmpty = true;
                    textBox.BackColor = Color.Red;
                }               
            }

            if ((!someEmpty) & (!main.CheckToCreateBook) & (!main.CheckToAdd)) //если не пустые и нажата сохранить и выбрана книга то добавляем
            {              
                main.dataGridView1.Rows.Add(textBox1.Text, textBox2.Text, "book", dateTimePicker1.Value.Year.ToString(), textBox4.Text, textBox5.Text);
                main.dataGridView1.AutoResizeColumns();
                this.Close();
            }

            if ((!someEmpty) & (main.CheckToCreateBook) & (!main.CheckToAdd)) //если не пустые и нажата изменить и выбрана книга то редактируем
            {
                //сначала удаляем текущую запись, потом записываем изменения             
                int delete = main.dataGridView1.SelectedCells[0].RowIndex;
                main.dataGridView1.Rows.RemoveAt(delete);
                main.dataGridView1.Rows.Add(textBox1.Text, textBox2.Text, "book", dateTimePicker1.Value.Year.ToString(), textBox4.Text, textBox5.Text);
                main.CheckToCreateBook = false; //переводим в режим добавления, а не редактирования      
                main.dataGridView2.AutoResizeColumns();
                this.Close();
            }

            if ((!someEmpty) & (!main.CheckToCreateJournal) & (main.CheckToAdd)) //если не пустые и нажата сохранить и выбран журнал
            {
                main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", dateTimePicker1.Value.Year.ToString(), textBox4.Text, textBox5.Text);
                this.Close();
            }
            if ((!someEmpty) & (main.CheckToCreateJournal) & (main.CheckToAdd))//если не пустые и нажата изменить и выбран журнал
            {
                int delete = main.dataGridView2.SelectedCells[0].RowIndex;
                main.dataGridView2.Rows.RemoveAt(delete);
                main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", dateTimePicker1.Value.Year.ToString(), textBox4.Text, textBox5.Text);
                main.CheckToCreateJournal = false; //переводим в режим добавления, а не сохранения
                this.Close();
            }

            main.AllResize();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            (sender as TextBox).BackColor = Color.Empty; //Если заполнили то убираем красный цвет
        }

        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            Form1 main = this.Owner as Form1;
            if (!main.CheckToAdd) // Если книга
            {
                if (Char.IsDigit(e.KeyChar) == false) return; // Если символ не цифра, то возвращаемся из метода
                e.Handled = true;
                return;
            }
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            Form1 main = this.Owner as Form1;
            if (main.CheckToAdd) // Если журнал
            {
                if (Char.IsDigit(e.KeyChar) == true) // Если символ цифра, то возвращаемся из метода
                {
                    return;
                }
                e.Handled = true;
                return;
            }
        }
               
       
    }
}
