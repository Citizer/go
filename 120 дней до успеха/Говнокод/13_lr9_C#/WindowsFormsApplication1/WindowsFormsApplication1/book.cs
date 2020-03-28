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
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            main.dataGridView1.Rows.Add(textBox1.Text, textBox2.Text, "book", textBox3.Text, textBox4.Text, textBox5.Text);
            this.Close();
        }
    }
}
