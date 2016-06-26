using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DLLGetFile;
using System.IO;
using Microsoft.Win32;

namespace Player
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.axWindowsMediaPlayer1.stretchToFit = true;             //自动缩放。
            this.axWindowsMediaPlayer1.settings.setMode("loop", true);      //循环播放。
            /*using (RegistryKey userKey = Application.UserAppDataRegistry)
            {
                if ((this.folderBrowserDialog1.SelectedPath = userKey.GetValue("MyMedia") as string) == null)
                {
                    this.folderBrowserDialog1.SelectedPath = Environment.
               GetFolderPath(Environment.SpecialFolder.MyMusic); //系统下的MyMusic文件夹              
                }
                AddFiles();
            }*/
        }
        private void AddFiles()
        {
            listView1.BeginUpdate();
            int count=this.axWindowsMediaPlayer1.currentPlaylist.count;
            Class1 lf = new Class1();                               //实例化动态链接库中的Class1类
            ListViewItem[] lvi = lf.searchDirectoryFile(this.folderBrowserDialog1.SelectedPath);
            for (int i = 0; i < lvi.Length; i++)
            {
                int exist=0;
                if (lvi[i] == null)
                { break; }
                else
                {
                    for (int j = 0; j < count; j++)
                    {
                        if (this.axWindowsMediaPlayer1.currentPlaylist.Item[j].sourceURL.Equals(lvi[i].SubItems[2].Text))
                        {
                            exist = 1;
                            break;
                        }
                    }
                    if(exist==0)
                    {
                        lvi[i].SubItems[0].Text = (listView1.Items.Count + 1).ToString();   //显示序列号
                        this.axWindowsMediaPlayer1.currentPlaylist.appendItem(this.axWindowsMediaPlayer1.newMedia(lvi[i].SubItems[2].Text));                     //添加文件路径
                        this.listView1.Items.Add(lvi[i]);                               //显示在播放列表中      update1 添加音乐文件夹不删除原有音乐列表
                    }
                }
                listView1.EndUpdate();
            }
        }

        private void 添加文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                listView1.BeginUpdate();
                Class1 lf = new Class1();
                string[] strFile = this.openFileDialog1.FileNames;              //选择多个文件
                int exist = 0;
                for (int i = 0; i < strFile.Length; i++)
                {
                    ListViewItem lvi = lf.searchFile(strFile[i]);
                    for (int j = 0; j < listView1.Items.Count; j++)
                    {
                        if (this.axWindowsMediaPlayer1.currentPlaylist.Item[j].sourceURL.Equals(lvi.SubItems[2].Text))  // update1 重名歌曲不重复添加
                        {
                            exist = 1;
                            break;
                        }
                    }
                    if (exist == 0)
                    {
                        lvi.SubItems[0].Text = (listView1.Items.Count + 1).ToString(); //显示序号
                        this.axWindowsMediaPlayer1.currentPlaylist.appendItem(this.axWindowsMediaPlayer1.
                        newMedia(lvi.SubItems[2].Text));                    //添加文件路径
                        this.listView1.Items.Add(lvi);                          //显示播放列表
                    }
                }
                listView1.EndUpdate();
            }
        }

        private void 添加文件夹ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.folderBrowserDialog1.ShowDialog() == DialogResult.OK)
            { AddFiles(); }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            switch (this.axWindowsMediaPlayer1.playState)               //播放状态
            {
                case WMPLib.WMPPlayState.wmppsTransitioning:            //准备新媒体
                case WMPLib.WMPPlayState.wmppsPlaying:              //在播放
                    int index = 1;
                    while (index < this.axWindowsMediaPlayer1.currentPlaylist.count-1)
                    {
                        if (this.axWindowsMediaPlayer1.currentMedia.get_isIdentical(this.
                         axWindowsMediaPlayer1.currentPlaylist.get_Item(++index)))
                        {
                            this.listView1.Items[index].EnsureVisible();        // update2 去除自动获取焦点
                            /*在窗体标题栏中显示所播放的文件名*/
                            this.Text = this.listView1.Items[index].SubItems[1].Text;
                            break;
                        }
                    }
                    break;
                case WMPLib.WMPPlayState.wmppsReady:                //播放准备就绪
                    this.axWindowsMediaPlayer1.Ctlcontrols.play();          //开始播放
                    break;
            }
        }

        private void listView1_MouseDoubleClick(object sender, MouseEventArgs e)//播放所选择的播放文件
        {
            if (this.listView1.SelectedItems.Count > 0)
            {
                int iSel = this.listView1.SelectedItems[0].Index;
                this.Text = this.listView1.SelectedItems[0].SubItems[1].Text.Trim();
                if (iSel <= this.axWindowsMediaPlayer1.currentPlaylist.count)
                {
                    this.axWindowsMediaPlayer1.Ctlcontrols.playItem(this.axWindowsMediaPlayer1.
                currentPlaylist.get_Item(iSel));
                }
            }
        }

        private void 列表折叠ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.splitContainer1.Panel2Collapsed = !this.splitContainer1.Panel2Collapsed;
            if (this.splitContainer1.Panel2Collapsed)
            { 列表折叠ToolStripMenuItem.Text = "播放列表展开"; }
            else
            { 列表折叠ToolStripMenuItem.Text = "播放列表折叠"; }
    }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)   //关闭窗体
        {
            using (RegistryKey subKey = Application.UserAppDataRegistry)
            { subKey.SetValue("MyMedia", this.folderBrowserDialog1.SelectedPath); }//写到注册表中
        }

        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("简易播放器\n庄瑞铭制作\nQQ:592129729\n更新内容:\n1.新增歌曲不再清空原列表\n2.可以删除歌曲了\n3.播放列表可以右键快速编辑了\n4.去除播放列表自动聚焦\n最后修改于2015年9月27号", "关于", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void 删除ToolStripMenuItem_Click(object sender, EventArgs e)      //update3 加入删除功能
        {
            if (listView1.SelectedItems.Count == 0)
                return;
            int iSel = this.listView1.SelectedItems[0].Index;
            listView1.Items.RemoveAt(iSel);
            this.axWindowsMediaPlayer1.currentPlaylist.removeItem(this.axWindowsMediaPlayer1.currentPlaylist.get_Item(iSel));   //axwindowsmediaplayer也要去掉
            for (int i=iSel;i<listView1.Items.Count;i++)
            {
                int intType = Int32.Parse(listView1.Items[i].SubItems[0].Text);     //序号处理
                intType--;
                listView1.Items[i].SubItems[0].Text = intType.ToString();
            }

        }

        private void 添加文件ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            添加文件ToolStripMenuItem_Click(sender, e);
        }

        private void 添加文件夹ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            添加文件夹ToolStripMenuItem_Click(sender, e);
        }
        private void 删除文件ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            删除ToolStripMenuItem_Click(sender, e);
        }
        private void 清空列表ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.axWindowsMediaPlayer1.currentPlaylist.clear();         //清除其中文件
            listView1.Items.Clear();
        }

        private void 列表折叠ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            列表折叠ToolStripMenuItem_Click(sender, e);
        }
    }
}
