## Arduino TPIC6B595 Library

### Description
This arduino library controls the Texas Instruments TPIC6B595 Serial to Parallel Shift Register.
This library will use hardware SPI if configured to do so. To change it open config.h and edit USE_HARD_SPI to 1 or 0 to use Hardware SPI are Software SPI respectively. Please note, that if you use Hardware SPI you must set the SS pin to an output per the Arduino library reference or the Arduino can be put into slave mode.

### Authorship
Derek Chafin  
Github: @infomaniac50  
Blog: [www.coding-squared.com](http://www.coding-squared.com/)  
September 1, 2013  


### License
<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Arduino TPIC6B595 Library</span> by <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Derek Chafin</span> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US">Creative Commons Attribution-ShareAlike 3.0 Unported License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/infomaniac50/Arduino-TPIC6B595" rel="dct:source">https://github.com/infomaniac50/Arduino-TPIC6B595</a>.
