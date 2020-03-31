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
    public partial class journal : Form
    {
        public journal()
        {
            InitializeComponent();            
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.CustomFormat = "yyyy";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //проверка все textbox на пустоту, если пустой то закрасить красным
            Form1 main = this.Owner as Form1;
            bool someEmpty = false;
            foreach (TextBox textBox in Controls.OfType<TextBox>())
            {
                if (string.IsNullOrEmpty(textBox.Text))
                {
                    someEmpty = true;
                    textBox.BackColor = Color.Red;
                }
            }

            if ((!someEmpty) & (main.flagj.Text == "0")) //если не пустые и нажата сохранить
            {                
                main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", dateTimePicker1.Value.Year, textBox4.Text, textBox5.Text);
                this.Close();
            }
            if ((!someEmpty) & (main.flagj.Text == "1")) //если не пустые и нажата изменить
            {
                int delete = main.dataGridView2.SelectedCells[0].RowIndex;
                main.dataGridView2.Rows.RemoveAt(delete);
                main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", dateTimePicker1.Value.Year, textBox4.Text, textBox5.Text);
                main.flagb.Text = "0";
                this.Close();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            (sender as TextBox).BackColor = Color.Empty; //Если заполнили то убираем красный цвет
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Char.IsDigit(e.KeyChar) == true) return; // Если символ цифра, то возвращаемся из метода
            e.Handled = true;
            return;
        }
    }
}
