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
    public partial class Form5 : Form
    {
        RichTextBox newlb;
        public Form5(RichTextBox lb)
        {
            InitializeComponent();
            newlb = lb;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String slocate = textBox1.Text;
            int locate = Int32.Parse(slocate);
            Form1.A.deletelink(locate);
            newlb.Text = Form1.A.printnode();
            this.Close();
        }
    }
}
