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

# Executables 
EXECUTABLE = 6 \
	jianzhi_offer_9

# output file
OUTFILE = outfile

# Log file
# LOG = 

#------------------------------------

default: all 

all: $(EXECUTABLE)

# $<: first prerequisite, here is src/CoinFlipper.cc
# $@: target name, her is coin_flipper
main: $(SRC)/main.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

6: $(SRC)/6.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

jianzhi_offer_9: $(SRC)/jianzhi_offer/9.cc
	$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	rm -f $(EXECUTABLE) $(OUTFILE) */*.o */*/*.o