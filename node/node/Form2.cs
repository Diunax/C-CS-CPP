using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace node
{
    public partial class Form2 : Form
    {
        RichTextBox newlb;
        public Form2(RichTextBox lb)
        {
            InitializeComponent();
            newlb = lb;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String content = textBox1.Text;
            string[] array = content.Split(new char[] { ' ', '\n' });
            foreach(string s in array)
            {
                Form1.A.addlink(s);
            }
            newlb.Text = Form1.A.printnode();
            this.Close();
        }
    }
}
