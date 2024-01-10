public class ArduinoController
{
    private SerialPort puertoSerial;
    private bool ledEncendido;

    public ArduinoController(string puerto)
    {
        puertoSerial = new SerialPort(puerto, 9600);
        try
        {
            puertoSerial.Open();
        }
        catch (Exception ex)
        {
            MessageBox.Show("Error al abrir el puerto: " + ex.Message);
        }
    }

    public static string DetectArduinoPort()
    {
        var ports = SerialPort.GetPortNames();
        foreach (string port in ports)
        {
            try
            {
                SerialPort serialPort = new SerialPort(port, 9600);
                serialPort.ReadTimeout = 500;
                serialPort.WriteTimeout = 500;
                serialPort.Open();
                serialPort.Write("identificar"); // Reemplazar con tu comando
                string response = serialPort.ReadLine();

                if (response.Contains("ArduinoAqui")) // Reemplazar con la respuesta esperada del Arduino
                {
                    serialPort.Close();
                    return port;
                }

                serialPort.Close();
            }
            catch (Exception ex)
            {
                //MessageBox.Show("puerto intentado: "+port +" "+ex.ToString());
            }
        }

        return null; // No se encontró el Arduino
    }


    public void ToggleLED()
    {
        if (puertoSerial != null && puertoSerial.IsOpen)
        {
            string comando = ledEncendido ? "apagar" : "encender";
            SendCommand(comando);
            ledEncendido = !ledEncendido;
        }
    }

    public void SendCommand(string comando)
    {
        if (puertoSerial != null && puertoSerial.IsOpen)
        {
            puertoSerial.WriteLine(comando);
        }
    }
}