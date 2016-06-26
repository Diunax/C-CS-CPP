using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace node
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
        public string data;
        public Node next;
        public Node(string c)
        {
            data = c;
            next = null;
        }
    }
    public class linknode
    {
        public Node head;
        public Node tail;
        public Node p,q,temp;
        public string result;
        public int count;
        public linknode()
        {
            head = null;
            tail = null;
            count = 0;
        }
        public void addlink(string c)
        {
            if (head == null && tail == null)
            {
                p = new Node(c);
                tail = head = p;
                count = 1;
            }
            else
            {
                p = new Node(c);
                tail.next = p;
                tail = p;
                count++;
            }
        }
        public void clear()
        {
            head = null;
            tail = null;
            count = 0;
        }
        public string printnode()
        {
            if (head == null) result = "";
            else
            {
                p = head;
                for (int i = 1; i <= count; i++)
                {
                    if (i == 1) result = p.data;
                    else result = result + " " + p.data;
                    p = p.next;
                }
            }
            return result;
        }
        public void insertlink(string c, int locate)
        {
            q = new Node(c);
            p = head;
            if (locate == 1)
            {
                q.next = p;
                head = q;
            }
            else if(locate>1&&locate<=count)
            {
                temp = new Node(null);
                for (int i = 1; i < locate; i++)
                {
                    temp = p;
                    p = p.next; //查找到插入位置的当前位置
                }
                temp.next = q;
                q.next = p;
            }
            else
            {
                tail.next = q;
                tail = q;
            }
            count++;
        }
        public void deletelink(int locate)
        {
            p = head;
            if(locate==1)
            {
                head = p.next;
            }
            else if (locate>1&&locate<count)
            {
                temp = new Node(null);
                for(int i=1;i< locate;i++)
                {
                    temp = p;
                    p = p.next;
                }
                temp.next = p.next;
            }
            else
            {
                temp = new Node(null);
                for (int i = 1; i < locate; i++)
                {
                    temp = p;
                    p = p.next;
                }
                temp.next = null;
                tail = temp;
            }
            count--;
        }
        public void inverstlink()
        {
            q = new Node(null);
            p = head;
            head = tail = q;
            for(int i=1;i<=count;i++)
            {
                q.data = p.data;
                q.next = head;
                head = q;
                q = new Node(null);
                p = p.next;
            }
        }
    }
}
