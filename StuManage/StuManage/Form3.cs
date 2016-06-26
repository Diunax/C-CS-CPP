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
    public partial class Form3 : Form
    {
        public ListView lv2;
        public Form3(ListView lv)
        {
            lv2 = lv;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string sat = textBox1.Text;
            int at = Int32.Parse(sat);
            if (at > 0 && at <= Form1.A.getcount())
            {
                Form1.A.delete(at);
                int count = Form1.A.getcount();
                lv2.BeginUpdate();
                lv2.Items.Clear();
                for (int i = 1; i <= count; i++)
                {
                    string result = Form1.A.print(i);
                    string[] array2 = result.Split(new char[] { ' ', '\n' });
                    ListViewItem lvi = new ListViewItem();
                    lvi.Text = i + "";
                    foreach (string c in array2)
                    {
                        lvi.SubItems.Add(c);
                    }
                    this.lv2.Items.Add(lvi);

                }
                lv2.EndUpdate();
            }
            else
            {
                MessageBox.Show("超出范围！删除失败!");
            }
            this.Close();
        }
    }
}
