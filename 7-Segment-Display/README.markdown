I just discovered that there are 2 types or 7 Segment displays,
<br>
One with Power HIGH,which means you send 1 to turn a segment ON , and
<br>
Power LOW,which means you turn segments ON by sending ZEROs!
<br>
Assuming a,b,c,d,e,f,g pins are connected to 1 single port (0~6) in order , as shown in the following image of Power HIGH connected 7-segment-display:
<br>
<img src="http://a.yfrog.com/img877/2271/kwx.gif">
<br>
Remember old school stuff, if you want to invert the bits in given 8-bit-number X is like saying 11111111-X or (2^8-1)-X or just 255-X....so,when I made the Power HIGH configuration,it was easy to invert it to the Power LOW configuration :)
<br>
<br>
POWER HIGH Configuration
{
// for e.g: you need to light the segments 0,1,2,3,4,5 to draw a 0
<br>
//0:
<br>
(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<4) |
(1<<5),

<br>
//1
<br>

(1<<1) |
(1<<2),

<br>
//2
<br>

(1<<0) |
(1<<1) |
(1<<6) |
(1<<4) |
(1<<3),

<br>
//3
<br>

(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<6),

<br>
//4
<br>

(1<<1) |
(1<<2) |
(1<<5) |
(1<<6),

<br>
//5
<br>

(1<<0) |
(1<<5) |
(1<<6) |
(1<<2) |
(1<<3),

<br>
//6
<br>

(1<<0) |
(1<<5) |
(1<<6) |
(1<<2) |
(1<<3) |
(1<<4),

<br>
//7
<br>

(1<<0) |
(1<<1) |
(1<<2),

<br>
//8
<br>

(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<4) |
(1<<5) |
(1<<6),

<br>
//9
<br>

(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<5) |
(1<<6)
