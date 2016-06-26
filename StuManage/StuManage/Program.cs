using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StuManage
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
    public class Node
    {
        public string id,name,date,sex,tel,address;
        public int num;
        public Node next;
        public Node(String[] a)
        {
            id = a[0];
            name = a[1];
            date = a[2];
            sex = a[3];
            tel = a[4];
            address = a[5];
            next = null;
        }
    }
    public class student
    {
        public Node head;
        public Node tail;
        public Node p, q, temp;
        public int searchcount;
        public string result;
        public int count;
        public student()
        {
            head = null;
            tail = null;
            count = 0;
        }
        public int getcount()
        {
            return count;
        }
        public void addstu(String[] a)
        {
            if (head == null && tail == null)
            {
                p = new Node(a);
                tail = head = p;
                count = 1;
                p.num = 1;
            }
            else
            {
                p = new Node(a);
                tail.next = p;
                tail = p;
                count++;
                p.num = count;
            }
        }
        public void delete(int at)
        {
            p = head;
            if (at > 1 && at < count)
            {
                for (int i = 1; i < at; i++)    //删除的元素位于1-count之间
                {
                    temp = p;   //要删除的上一节点
                    p = p.next;     //要删除的节点
                }
                temp.next = p.next;
            }
            else if (at == 1 && count > 1)
            {
                head = head.next;
            }
            else if (at == 1 && count == 1)
            {
                clear();
            }
            else if(at==count&&count!=1)
            {
                for(int i=1;i< at;i++)
                {
                    temp = p;
                    p = p.next;
                }
                temp = tail;
            }
            count--;
            p = head;
            for(int i=1;i<= count;i++)
            {
                p.num = i;
                p = p.next;
            }
        }
        public void clear()
        {
            head = null;
            tail = null;
            count = 0;
        }
        public string print(int i)  //第一个为1
        {
            p = head;
            for(int j=1;j< i;j++)
            {
                p = p.next;
            }
            result = p.id + " " + p.name + " " + p.date + " " + p.sex + " " + p.tel + " " + p.address;
            return result;
        }
        public int getsearchcount()
        {
            //searchcount = 2;
            return searchcount;
        }
        public string search(string sid,string sname,string sdate,string ssex,string stel,string saddress)
        {
            string back=null;
            string rback = null;
            string[] array;
            searchcount = 0;
            p = head;
            /*第一个不为空的情况，下同*/
            if (sid.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.id == sid)
                    {
                        back = back +" "+p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if(back==null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
                array = back.Split(' ');
                if(sname.Length!=0) //当sname不为空时
                {
                    back = null ;
                    searchcount = 0;
                    foreach(string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for(int j=1;j< ii;j++)
                        {
                            p = p.next;
                        }
                        if(p.name==sname)
                        {
                            back = back + " "+p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if(sdate.Length!=0)     //当sdate不为空时
                {
                    rback = back;
                    back = "";
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.date == sdate)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (ssex.Length != 0)     //当ssex不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.sex == ssex)
                        {
                            back = back + " " + p.num ;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (stel.Length != 0)     //当stel不为空时
                {
                    searchcount = 0;
                    rback = back;
                    back = null;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.tel == stel)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (saddress.Length != 0)     //当saddress不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.address == saddress)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    array = back.Split(' ');
                }
                
            }
            /*第一个不为空的情况，下为第二、三...个不为空的情况*/
            else if (sname.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.name == sname)
                    {
                        back = back + " " + p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if (back == null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
                array = back.Split(' ');
                if (sdate.Length != 0)     //当sdate不为空时
                {
                    rback = back;
                    back = "";
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.date == sdate)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (ssex.Length != 0)     //当ssex不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.sex == ssex)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (stel.Length != 0)     //当stel不为空时
                {
                    searchcount = 0;
                    rback = back;
                    back = null;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.tel == stel)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (saddress.Length != 0)     //当saddress不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.address == saddress)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    array = back.Split(' ');
                }

            }
            /************************/
            else if (sdate.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.date == sdate)
                    {
                        back = back + " " + p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if (back == null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
                array = back.Split(' ');
                if (ssex.Length != 0)     //当ssex不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.sex == ssex)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (stel.Length != 0)     //当stel不为空时
                {
                    searchcount = 0;
                    rback = back;
                    back = null;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.tel == stel)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (saddress.Length != 0)     //当saddress不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.address == saddress)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    array = back.Split(' ');
                }

            }
            /**********************/
            else if (ssex.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.sex == ssex)
                    {
                        back = back + " " + p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if (back == null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
                array = back.Split(' ');
                if (stel.Length != 0)     //当stel不为空时
                {
                    searchcount = 0;
                    rback = back;
                    back = null;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.tel == stel)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    back = back.Substring(1, back.Length - 1);
                    array = back.Split(' ');
                }
                if (saddress.Length != 0)     //当saddress不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.address == saddress)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    array = back.Split(' ');
                }

            }
            /*********************/
            else if (stel.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.tel == stel)
                    {
                        back = back + " " + p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if (back == null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
                array = back.Split(' ');
                if (saddress.Length != 0)     //当saddress不为空时
                {
                    rback = back;
                    back = null;
                    searchcount = 0;
                    foreach (string i in array)
                    {
                        p = head;
                        int ii = Int32.Parse(i);
                        for (int j = 1; j < ii; j++)
                        {
                            p = p.next;
                        }
                        if (p.address == saddress)
                        {
                            back = back + " " + p.num;
                            searchcount++;
                        }
                    }
                    if (back == null) goto END;  //若找不出p.num，则跳结尾
                    array = back.Split(' ');
                }

            }
            /****************/
            else if (saddress.Length != 0)    //当sid不为空时
            {
                for (int i = 1; i <= count; i++)      //找出sid相等的p.num
                {
                    if (p.address == saddress)
                    {
                        back = back + " " + p.num;
                        searchcount++;
                    }
                    p = p.next;
                }
                if (back == null) goto END;  //若找不出p.num，则跳结尾
                back = back.Substring(1, back.Length - 1);
            }
            END:
            //back = "1 2";

            return back;    //返回的是节点num的字符串
            
        }
    }
}
