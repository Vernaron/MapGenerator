import os
mfb=open("makefileBuilderInfo", 'r')
CC=mfb.readline()
CFLAGS=mfb.readline()
finalname=mfb.readline()
print(CC)
print(CFLAGS)
print(finalname)
mfb.close()
allModules = []
# a module is a .cpp or .h file and all of it's dependents.
# headers can be a part of multiple modules
class Module:
    #takes a .cpp file, checks it's includes, and find the appropriate
    #header files
    #stops if a { is found
    def findHeaders(self, mainFile):
        self.headers = []
        headCheck = open(mainFile, 'r')
        currFile =  headCheck.readlines()
        for line in currFile:
            if '{' in line:
                break
            if '"' in line:
                self.headers.append(line[10:-2])
        headCheck.close()
    def __init__(self, mainFile):
        self.mainFile=mainFile
        self.findHeaders(mainFile)
    def writeSelf(self, makefile):
        if ".cpp" in self.mainFile:
            makefile.write(self.mainFile[:-4]+".o:")
        elif ".c" in self.mainFile:
            makefile.write(self.mainFile[:-2]+".o:")
        makefile.write(self.mainFile)
        for header in self.headers:
            makefile.write(" "+header)
        makefile.write("\n\t$(CC) $(CFLAGS) "+self.mainFile+" -c\n")
print(" ")
for path, subdirs, files in os.walk("."):
    for name in files:
        if "dist" not in files:
            if name.endswith(".c") or name.endswith(".cpp"):
                a = Module(name)
                allModules.append(a)
for each in allModules:
    print(each.mainFile)
    print (each.headers)
#last compilation lines
makefile=open("makefile", "w")
makefile.write(CC+CFLAGS)
makefile.write("\n"+finalname+":")
for module in allModules:
    makefile.write(module.mainFile[:-4]+".o ")
makefile.write("\n\t$(CC) $(CFLAGS) ")
#all compilations other than the last
for module in allModules:
    makefile.write(module.mainFile[:-4]+".o ")
makefile.write("-o "+finalname+"\n\t./"+finalname+"\n")
for module in allModules:
    module.writeSelf(makefile)
    
makefile.close()
input("Completed, Press Enter to Close:")
