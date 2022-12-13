## computer graphics - openGL

### Watch:
```bash
# Link full installed
https://www.youtube.com/watch?v=-up6JCZuYE4
```

### Download:
```bash
# Dev-C
https://sourceforge.net/projects/orwelldevcpp/

# FreeGLUT MinGW
https://www.transmissionzero.co.uk/software/freeglut-devel/
```

### Install:
```bash
# Project Option -> Parameters -> Linker
-lopengl32 
-lfreeglut 
-lglu32
```

### Fix error: freeglut  ERROR:  Function <glutCreateWindow> called without first calling 'glutInit'.
```bash
# int main(int argc, char *argv[])
# add to main
glutInit(&argc, argv);
```




