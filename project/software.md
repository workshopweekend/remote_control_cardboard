1.  First, test your motor wiring by running the following motor testing code:
    <%= motor_tester.ino =%>
    
2.  The wheels should move forward for a second, then stop for a second, and repeat. If either or both wheels are rotating in the wrong direction, switch two connectors around on those wheels.

3.  Install the [IR Remote library](http://workshopweekend.net/img/arduino-projects/IRremote.zip): in Arduino, in the "Sketch" menu, select "Import Library..." then "Add Library...", and in the resulting diablog box, navigate to the `IRremote.zip` file you just downloaded. (Note: this library conflicts with a built-in library in Arduino version 1.6.0 -- if you're getting a strange error, try Arduino version 1.0.6!)

4.  Upload the full remote control cardboard box code, but note that your remote control won't trigger the wheels yet:
    <%= remote_control_cardboard.ino %=>
    
5.  Update your code (in the `void loop()` function) so that the control functions (`forward`, `reverse`, `left`, `right`, and `halt`) are triggered by specific buttons on your remote.

    To do this, open the Serial Monitor in Arduino, and press the button on your remote that you want to make the box move forward. Note down which number appears in the serial monitor. This is the hexadecimal version of the number the remote sends when you press the button.
    
    Find the `if` or `else if` line that falls above the `"FORWARD"` line. Update the condition `(results.value == 0xABCD)`, replacing `ABCD` with the number you found above.
    
    Test and repeat for the 4 other commands!
