#------------------------------------
# Choose Relase or Debug mode by
# uncommenting one of the following
# lines:

#OPT = -O2 -DNDEBUG # Production
OPT = -g # Debug
#------------------------------------


#------------------------------------
# Options for gcc toolchain

CXX = g++
CXXFLAGS = -std=c++11 -I. -I ./include $(OPT)
#LDFLAGS = 
#------------------------------------


#------------------------------------
# Source files and target names

SRC = ./src

# Library
LIB_SRC = $(SRC)/utils/list_node.cc
LIBOBJECTS = $(LIB_SRC:.cc=.o)
LIBRARY = libdsa.a

# Executables 
EXECUTABLE = main \
	jianzhi_offer_6 \
	jianzhi_offer_9 \
	leetcode_155

# output file
OUTFILE = outfile

# Log file
# LOG = 

#------------------------------------

default: all 

all: $(LIBRARY) $(EXECUTABLE)

$(LIBRARY): $(LIBOBJECTS)
	rm -rf $@
	$(AR) -rs $@ $(LIBOBJECTS)

# $<: first prerequisite, here is src/CoinFlipper.cc
# $@: target name, her is coin_flipper
main: $(SRC)/main.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

6: $(SRC)/6.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

leetcode_155: $(SRC)/leetcode/155.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

jianzhi_offer_6: $(SRC)/jianzhi_offer/6.cc
	$(CXX) $(CXXFLAGS) $< -o $@ -L. $(LIBRARY) 

jianzhi_offer_9: $(SRC)/jianzhi_offer/9.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	rm -f $(LIBRARY) $(EXECUTABLE) $(OUTFILE) */*.o */*/*.o