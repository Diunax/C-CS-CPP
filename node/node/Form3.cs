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
    public partial class Form3 : Form
    {
        String content = null;
        String output = "查找成功，位于位置 ";
        bool find;
        int i = 1;
        public Form3(RichTextBox lb)
        {
            InitializeComponent();
            content = lb.Text;
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            string[] array = content.Split(new char[] { ' ', '\n' });
            foreach (string s in array)
            {
                if(s == textBox1.Text)
                {
                    output = output + i + " ";
                    find = true;
                }
                i++;
            }
            if (find) MessageBox.Show(output);
            else MessageBox.Show("查找失败！未找到该元素!");
            this.Close();
        }
    }
}
