﻿using System;
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
            port = new SerialPort("COM10", 9600);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                port.Open();
                port.Write("!Available&");
                port.Close();
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
                port.Open();
                port.Write("!Occupied&");
                port.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
