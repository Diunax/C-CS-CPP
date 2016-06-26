using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace StuManage
{
    public partial class Form1 : Form
    {
        public String file;
        public static student A;
        public Form1()
        {
            A = new student();
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog Stu = new OpenFileDialog();
            Stu.Filter = "linknode savefile (*.txt)|*.txt"; //过滤文件类型
            Stu.ShowReadOnly = false; //设定文件是否只读
            if (Stu.ShowDialog() == DialogResult.OK)
            {
                A.clear();
                FileStream text = new FileStream(Stu.FileName, FileMode.Open);
                file = Stu.FileName; //获取打开的文件名
                StreamReader ln = new StreamReader(text,System.Text.Encoding.Default);
                ln.BaseStream.Seek(0, SeekOrigin.Begin);
                string strLine;
                while ((strLine = ln.ReadLine()) != null)
                {
                    if (strLine != null)          //考虑文件为空的情况
                    {
                        string[] array = strLine.Split(new char[] { ' ', '\n' });
                        A.addstu(array);
                    }
                    else
                    {
                        MessageBox.Show("文件内容不符合读入要求！");
                    }
                }
                print();
                ln.Close();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            print();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            MessageBoxButtons messButton = MessageBoxButtons.OKCancel;
            DialogResult dr = MessageBox.Show("是否要保存?", "退出", messButton);
            if (dr == DialogResult.OK)
            {
                button5_Click(sender,e);
                this.Close();
            }
            else
            {
                this.Close();
            }
                
        }
        public void print()
        {
            int count = A.getcount();
            listView1.BeginUpdate();
            listView1.Items.Clear();
            for (int i = 1; i <= count; i++)
            {
                string result = A.print(i);
                string[] array = result.Split(new char[] { ' ', '\n' });
                ListViewItem lvi = new ListViewItem();
                lvi.Text = i+"";
                foreach (string c in array)
                {
                    lvi.SubItems.Add(c);
                }
                this.listView1.Items.Add(lvi);

            }
            listView1.EndUpdate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            A.clear();
            print();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form fm = new Form2(listView1);
            fm.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            FileStream fs = null;
            try
            {
                if (file != null) { }
                else
                {
                    SaveFileDialog file2 = new SaveFileDialog();
                    file2.Filter = "文本文件|*.txt";
                    if (file2.ShowDialog() == DialogResult.OK)
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
                        int count = A.getcount();
                        for(int i=1;i<= count;i++)
                        {
                            sw.Write(A.print(i)+"\r\n");
                        }
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

        private void button3_Click(object sender, EventArgs e)
        {
            Form fm = new Form3(listView1);
            fm.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form fm = new Form4(listView1);
            fm.Show();
        }
    }
}
