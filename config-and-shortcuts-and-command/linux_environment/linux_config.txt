

# install 'oh my zsh' pulg manage of zsh.
wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O ~/Downloads/ohmyzsh

$(~/Downloads/ohmyzsh)

# ? -> whatis command. 

sudo apt install cowsay  

cat 'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' >> ~/.bashrc  

cat 'alias ?=\'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)\'' >> ~/.bashrc



