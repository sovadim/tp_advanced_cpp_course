# Build process lib
mkdir -p hw2_loglib/build
cd hw2_loglib/build
cmake ..
make
cd ../..

# Build samples
mkdir -p hw2_loglib/samples/demo/build
cd hw2_loglib/samples/demo/build
cmake ..
make
cd ../../..
