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
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 main = this.Owner as Form1;
            main.dataGridView2.Rows.Add(textBox1.Text, textBox2.Text, "journal", textBox3.Text, textBox4.Text, textBox5.Text);
            this.Close();
        }
    }
}
