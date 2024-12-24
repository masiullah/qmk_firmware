#Compile
time qmk compile -kb crowboard_pico/rev2 -km default -c -j 8
#Clean compile
time qmk compile -kb crowboard_pico/rev2 -km default -j 8
#copy the file to the host os
cp crowboard_pico_rev2_default.uf2 /tmp/lima/ &&  ls -ahl crowboard_pico_rev2_default.uf2