#XML Pretty Printer

This is a tiny utility I made in C++ using tinyxml2. It reads an xml string as a command line argument, or from STDIN, formats it, and then prints it to STDOUT.

I made it because the damn ebay api gave giant error messages that I needed to pretty print to look at.

###Installation
```
git clone https://github.com/rafkhan/xml-pretty-printer.git
cd xml-pretty-printer
make install
```

###Example
```
$ pp "<Github><Users><User><Name>rafkhan</Name><Awesomeness>over 9000</Awesomeness></User><User><Name>uiri</Name><Awesomeness>Less than rafkhan</Awesomeness></User><User><Name>aaronhamilton</Name><Awesomeness>Too good for you.</Awesomeness><Description>The single most classy man you'll ever see. A womanizer. A god among men. Master of the sandwich.</Description></User></Users></Github>"
```

Will print...

```
<Github>
    <Users>
        <User>
            <Name>rafkhan</Name>
            <Awesomeness>over 9000</Awesomeness>
        </User>
        <User>
            <Name>Uiri</Name>
            <Awesomeness>Less than rafkhan</Awesomeness>
        </User>
        <User>
            <Name>aaronhamilton</Name>
            <Awesomeness>Too good for you.</Awesomeness>
            <Description>The single most classy man you'll ever see. A womanizer. A god among men. Master of the sandwich.</Description>
        </User>
    </Users>
</Github>
```

####OR

```$ command_that_outputs_xml | pp```
