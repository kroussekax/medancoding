import serial
import sys

if len(sys.argv) < 4:
    print(f"Usage: python {sys.argv[0]} <port> <command> <value>")
    print(f"Example: python {sys.argv[0]} /dev/rfcomm0 1 25")
    sys.exit(1)

port    = sys.argv[1]
command = int(sys.argv[2])
value   = int(sys.argv[3])

bt = serial.Serial(port, 115200)
bt.write(bytes([command, value]))
print(f"Sent command={command} value={value} to {port}")
bt.close()
