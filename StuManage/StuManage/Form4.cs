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
    public partial class Form4 : Form
    {
        public ListView lv2;
        public Form4(ListView lv)
        {
            lv2 = lv;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string id, name, date, sex, tel, address;
            id = textBox6.Text;
            name = textBox5.Text;
            date = textBox4.Text;
            sex = textBox3.Text;
            tel = textBox2.Text;
            address = textBox1.Text;
            string text=Form1.A.search(id, name, date, sex, tel, address);
            //1 2;
            int count = Form1.A.getsearchcount();
            //2
            if (text == null) MessageBox.Show("查找失败！");
            else
            {
                lv2.BeginUpdate();
                lv2.Items.Clear();
                string[] array = text.Split(' ');
                //array[0] 1
                //array[1] 2
                foreach (string c in array)
                {
                    if (c.Length != 0)
                    {
                        int cc = Int32.Parse(c);
                        string result = Form1.A.print(cc);
                        string[] array3 = result.Split(' ');
                        ListViewItem lvi = new ListViewItem();
                        lvi.Text = cc + "";
                        foreach (string a in array3)
                        {
                            lvi.SubItems.Add(a);
                        }
                        this.lv2.Items.Add(lvi);
                    }
                }
                lv2.EndUpdate();
            }
            this.Close();
        }
    }
}
