make -C /home/aanchal/new_kernel/linux-5.19.9 && make nconfig
make -C /home/aanchal/new_kernel/linux-5.19.9 && make localmodconfig
make -C /home/aanchal/new_kernel/linux-5.19.9 && make nconfig
make -C /home/aanchal/new_kernel/linux-5.19.9 && make -j $(nproc)
