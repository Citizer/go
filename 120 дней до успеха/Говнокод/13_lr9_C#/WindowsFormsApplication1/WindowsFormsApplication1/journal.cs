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
            bool someEmpty = false;
            foreach (TextBox textBox in Controls.OfType<TextBox>())
            {
                if (string.IsNullOrEmpty(textBox.Text))
                {
                    someEmpty = true;
                    textBox.BackColor = Color.Red;
                }
            }

            if (!someEmpty) //если не пустые то заполняем
            {
                Form1 main = this.Owner as Form1;
                main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", dateTimePicker1.Value.Year, textBox4.Text, textBox5.Text);
                this.Close();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            (sender as TextBox).BackColor = Color.Empty; //Если заполнили то убираем красный цвет
        }
    }
}
