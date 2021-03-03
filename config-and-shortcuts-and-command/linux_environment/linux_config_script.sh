

# install 'oh my zsh' pulg manage of zsh.
# wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O ~/Downloads/ohmyzsh
#$(~/Downloads/ohmyzsh)

git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
chsh -s /bin/zsh

# ? -> whatis command. 

sudo apt install cowsay  

cat 'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' >> ~/.bashrc  

cat 'alias ?=\'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)\'' >> ~/.bashrc



