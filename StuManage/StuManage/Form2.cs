using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StuManage
{
    public partial class Form2 : Form
    {
        public ListView lv2;
        public Form2(ListView lv)
        {
            lv2 = lv;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string[] array = new string[6];
            array[0] = textBox6.Text;
            array[1] = textBox5.Text;
            array[2] = textBox4.Text;
            array[3] = textBox3.Text;
            array[4] = textBox2.Text;
            array[5] = textBox1.Text;
            Form1.A.addstu(array);
            int count = Form1.A.getcount();
            lv2.BeginUpdate();
            lv2.Items.Clear();
            for (int i = 1; i <= count; i++)
            {
                string result = Form1.A.print(i);
                string[] array2 = result.Split(new char[] { ' ', '\n' });
                ListViewItem lvi = new ListViewItem();
                lvi.Text = i+""; 
                foreach (string c in array2)
                {
                    lvi.SubItems.Add(c);
                }
                this.lv2.Items.Add(lvi);

            }
            lv2.EndUpdate();
            this.Close();
        }
    }
}
