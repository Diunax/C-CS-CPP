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
    public partial class Form4 : Form
    {
        RichTextBox newlb;
        public Form4(RichTextBox lb)
        {
            InitializeComponent();
            newlb = lb;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String slocate = textBox1.Text;
            int locate = Int32.Parse(slocate);
            String content = textBox2.Text;
            Form1.A.insertlink(content, locate);
            newlb.Text = Form1.A.printnode();
            this.Close();
        }
    }
}
