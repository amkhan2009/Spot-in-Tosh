# Mac N Chez

<img width="1494" height="875" alt="Screenshot 2026-04-17 040046" src="https://github.com/user-attachments/assets/629203f3-4ed7-4aaf-823c-1b5a5450f0b8" />


<img width="910" height="854" alt="Screenshot 2026-04-20 183306" src="https://github.com/user-attachments/assets/3ecd5546-cfd7-4b48-beaf-27c0f0e52909" />

**About**

The Spot N Tosh is a Macintosh-inspired Spotify display built following the Stasis guided project. It combines retro Mac aesthetics with modern microcontroller tech — a tiny desktop companion that shows what's playing on Spotify in classic compact Mac style.
The project features a fully custom-made case with slotted air cooling vents and a built-in display riser, giving the screen the perfect angle while keeping the whole build thermally happy.

**Hardware**
ESP32 DevBoard 
the head of operations links everything together

TFT Screen 
Main Spotify display output

Key Switches
Physical playback controls

GPIO Ports
Power extension and component linkage

**Case Design**
Custom enclosure styled after the classic Macintosh form factor
Slotted air cooling vents for passive thermal management
Built in display riser to angle the  screen at the perfect viewing height


**How It Works**
The ESP32 DevBoard is the brain of the Spot N Tosh, acting as the central hub that links the TFT screen, key switches, and power supply together. All components are wired through the GPIO ports using a power extension approach  similar in spirit to how the original Mac routed its internals making the ESP32 the single point of control for display output and key input.




**Built With**
Stasis Guided Project
ESP32 Arduino
TFT display drivers
Spotify Web API


**BOM**
| Component | Description | QTY | Link | Price |
| -------- | -------- | -------- | -------- | -------- |
| LOLIN C3 Mini V2.1.0 | ESP32-C3FH4 WiFi + BLE, 4MB Flash — main controller | 1 | 4.5 | https://www.aliexpress.us/item/3256804553736450.html |
| CCA4 1.8" TFT LCD | ST7735 SPI, 128×160 resolution — Spotify display | 1 | 3 | [https://www.aliexpress.us/item/3256804553736450.html](https://www.aliexpress.us/item/3256809508197532.html) |
| Holy Panda Tactile Switch | 3-pin, 55g–67g POM mechanical switch — playback control | 1 | 3 | [https://www.aliexpress.us/item/3256804553736450.html](https://www.aliexpress.us/item/3256804202248944.html) |
| Jumper Wires | 	Connect board to screen and keys | 1 | 2.5 |[ https://www.aliexpress.us/item/3256804553736450.html](https://www.aliexpress.us/item/3256803032782196.html?spm=a2g0n.shopcart.0.0.341238daOvLsRQ&mp=1&pdp_npi=6%40dis%21USD%21USD+4.61%21USD+4.43%21%21USD+4.43%21%21%21%402101c44f17771887062764288e21c9%2112000024783046589%21ct%21US%217551140146%21%211%210%21&_gl=1*1ueby3g*_gcl_aw*R0NMLjE3NzYxMzA3MDkuQ2owS0NRandxUExPQmhDaUFSSXNBS1JNUFpyQTJrR1NIWjhjRzFXOEtCSVdWcWxLX25wLUM3ZWFOdThBUFVmdVlFeXFJVlA1dDltZ2hqc2FBbTRFRUFMd193Y0I.*_gcl_dc*R0NMLjE3NzYxMzA3MDkuQ2owS0NRandxUExPQmhDaUFSSXNBS1JNUFpyQTJrR1NIWjhjRzFXOEtCSVdWcWxLX25wLUM3ZWFOdThBUFVmdVlFeXFJVlA1dDltZ2hqc2FBbTRFRUFMd193Y0I.*_gcl_au*MTg5OTc0NjY2OS4xNzc2MTMwNzQx*_ga*MTU5MDY5MjIwNS4xNzc3MTg4MjE4*_ga_VED1YSGNC7*czE3NzcxODgyMTgkbzEkZzEkdDE3NzcxODg3MDgkajYwJGwwJGgw&gatewayAdapt=glo2usa) |


Made with nostalgia
