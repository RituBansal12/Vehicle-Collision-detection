String start_request = ""; 
String end_request = "";

start_request = start_request +
 "\n--AaB03x\n" +
 "Content-Disposition: form-data; name=\"userfile\"; filename=\"CAM.JPG\"\n" +
 "Content-Transfer-Encoding: binary\n\n";
 
end_request = end_request + "\n--AaB03x--\n";

uint16_t full_length;

full_length = start_request.length() + len + end_request.length();

client.println("POST //address");
client.println("Host: asi.lv");
client.println("Content-Type: multipart/form-data; boundary=AaB03x");
client.print("Content-Length: "); client.println(full_length);
client.print(start_request);

// Read image data from cam and send away to internet
 static const size_t bufferSize = 1024; 
 static uint8_t buffer[bufferSize] = {0xFF};
 while (len) {
 size_t will_copy = (len < bufferSize) ? len : bufferSize;
 SPI.transferBytes(&buffer[0], &buffer[0], will_copy);
 if (!client.connected()) break;
 client.write(&buffer[0], will_copy);
 len -= will_copy; }
 client.println(end_request);
 myCAM.CS_HIGH(); digitalWrite(led, HIGH);
}
 client.println(end_request);
