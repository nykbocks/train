# About the Train library
This is a self made,Nob inspired library: [Nob github](www.github.com/tsoding/nob.h),this library will not only contain string manipulation: THIS IS A EARLY STAGE LIBRARY,NOTHING IS FINISHED NEIHTER POLISHED! [Train repo](www.github.com/nykbocks/train)
## String Functions
| Function     | Description                                                                   | Usage                                                                 |
|--------------|-------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| tn_str       | Creates a string object,with the item (the string), and its size .            | Train_str hello = tn_str("Hello World!"                               |
| tn_size      | Retrieves the size of an  ordinary  string that is null terminated.           | int hello_size = tn_size("Hello World!");                             |
| tn_ret_print | Returns a formated string as  its output. Can be used to concatanate strings: | Train_str concatenate = tn_str(tn_ret_print("%s%s","Hello","World!")) |
| tn_ins   | Inserts a string inside another string.                             | Train_str hello = tn_str("HW!") tn_ins(hello,1,"ello ") // new string: Hello W! tn_ins(hello,7,"orld") // new string: Hello World! printf("%s",hello.item); |   |   |
