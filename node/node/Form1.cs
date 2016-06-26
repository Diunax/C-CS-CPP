using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace node
{
    public partial class Form1 : Form
    {
        public string file;
        public static linknode A;
        public Form1()
        {
            A = new linknode();
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)  //读取txt文件
        {
            OpenFileDialog linknode = new OpenFileDialog();
            linknode.Filter = "linknode savefile (*.txt)|*.txt"; //过滤文件类型
            linknode.ShowReadOnly = false; //设定文件是否只读
            if(linknode.ShowDialog()==DialogResult.OK)
            {
                A.clear();
                FileStream text = new FileStream(linknode.FileName, FileMode.Open);
                file = linknode.FileName; //获取打开的文件名
                StreamReader ln = new StreamReader(text);
                ln.BaseStream.Seek(0, SeekOrigin.Begin);
                string strLine = ln.ReadLine();
                // label1.Text = strLine;
                if (strLine != null)          //考虑文件为空的情况
                {
                    string[] array = strLine.Split(new char[] { ' ', '\n' });
                    //label1.Text = array[0] + "zxc" + array[1] + "zxc" + array[2];
                    foreach (string c in array)
                    {
                        A.addlink(c);
                    }
                    richTextBox1.Text = A.printnode();
                }
                else
                {
                    MessageBox.Show("文件内容不符合读入要求！");
                }
                ln.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)  //保存到txt
        {
            FileStream fs = null;
            try
            {
                if (file != null) { }
                else
                {
                    SaveFileDialog file2 = new SaveFileDialog();
                    file2.Filter = "文本文件|*.txt";
                    if(file2.ShowDialog()==DialogResult.OK)
                    {
                        file = file2.FileName;
                    }
                }
                if (file != null)
                {
                    fs = new FileStream(file, FileMode.OpenOrCreate, FileAccess.ReadWrite);
                    fs.Seek(0, SeekOrigin.Begin);
                    fs.SetLength(0);
                    using (StreamWriter sw = new StreamWriter(fs, Encoding.Default))
                    {
                        sw.Write(A.printnode());
                    }
                }
                else
                {
                    MessageBox.Show("未选择保存路径！");
                }
            }
            finally
            {
                if (fs != null)
                    fs.Dispose();
            }
        }

        private void button3_Click(object sender, EventArgs e)  //初始化
        {
            A.clear();
            richTextBox1.Text = A.printnode();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            A.clear();
            Form2 fm2 = new Form2(richTextBox1);
            fm2.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Form3 fm3 = new Form3(richTextBox1);
            fm3.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form fm4 = new Form4(richTextBox1);
            fm4.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Form fm5 = new Form5(richTextBox1);
            fm5.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            A.inverstlink();
            richTextBox1.Text = A.printnode();
        }
    }
}
