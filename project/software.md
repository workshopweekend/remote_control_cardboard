1.  First, test your motor wiring by running the following motor testing code. The wheels should move forward for a second, then stop for a second, and repeat. If either or both wheels are rotating in the wrong direction, switch two connectors around on those wheels.
    <%= motor_tester.ino =%>
    
2.  Install the IR Remote library: in Arduino, in the "Sketch" menu, select "Import Library..." then "Manage Libraries...", and in the resulting window, search for "IRRemote" and install the library by "shirriff".

3.  Upload this remote control cardboard box testing code, but note that your remote control won't trigger the wheels yet:
    <%= remote_control_cardboard_limited.ino =%>

4.  Open the Serial Monitor in Arduino -- that's the magnifying glass icon in the upper-right corner of the window. Pick a button that you want to trigger your box's forward motion. Press that button and see which number appears in the serial monitor. This is the hexadecimal version of the number the remote sends when you press the button. Copy this number.

5.  Inside the `void loop()` function, find the `if` statement that falls above the `"FORWARD"` line. Update the condition `(results.value == 0xABCD)`, replacing `ABCD` with the number you found above. (Note: the `0x` prefix tells Arduino that the number is written in hexademical -- without it, you may get some strange error, or it may just not work at all!)
    
6.  Upload your code and make sure the forward button on your remote makes your box move forward. If it doesn't -- what went wrong? If nothing happens at all, check to make sure you are still seeing the same number in the serial monitor. If the box moves, but not in the direction you expect, check the forward & reverse pins for each motor.

7.  Repeat steps 4-6 for the `halt` function, picking a new button, copying it into the `"HALT"` `if` statement in the code, and testing.

8.  To fully control your box, you'll want extra control functions: at least `reverse`, `left`, and `right`. Each should be triggered by a specific button on your remote.

    Write functions for `reverse`, `left`, and `right` -- these will look very similar to the existing `forward` and `halt` functions, but with different `HIGH` and `LOW` settings depending on which way you want each motor to turn for each function. Place the new functions after the `forward` and `halt` functions, but not inside any other function. (These are top-level functions we can use from anywhere in the code!)

    Add additional `else if` statements for `reverse`, `left`, and `right`. These will look very similar to the `else if` statement for the `halt` function, except you'll compare `results.value` to a different button number, call the `reverse()`, `left()`, or `right()` function instead of `halt()`, and print a different string.

9.  Test! Your code may end up looking something like this:
    <%= remote_control_cardboard.ino =%>
