using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DebugBluetooth
{
    public partial class Form1 : Form
    {
        private SerialPort port = null;

        public Form1()
        {
            InitializeComponent();
            port = new SerialPort("COM11", 9600);
            port.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                //port.Open();
                port.Write("!Available&");
                //port.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                //port.Open();
                port.Write("!Occupied&");
                //port.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                port.Write("!Off&");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                port.Write("!On&");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
