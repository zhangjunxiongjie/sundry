
# config gdb
mkdir ~/.gdb
cp -r ./gdb-plugins ~/.gdb/
echo "source ~/.gdb/gdb-plugins/peda.py" > ~/.gdbinit
echo "source ~/.gdb/gdb-plugins/gef/gef.py" > ~/.gdbinit
echo "source ~/.gdb/gdb-plugins/gdbinit/gdbinit" > ~/.gdbinit

echo 'configuration gdb successful!!!'

# config vim
sudo cp -r ./vim-runtime /opt/
sudo chmod a+x /opt/vim-runtime/install_awesome_parameterized.sh
sudo /opt/vim-runtime/install_awesome_parameterized.sh /opt/vim-runtime --all

echo 'configuration vim successful!!!'

# config zsh shell

# install 'oh my zsh' pulg manage of zsh.
# wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O ~/Downloads/ohmyzsh
#$(~/Downloads/ohmyzsh)

git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh #
cp ./zsh_config_file.txt ~/.zshrc # config
cp -r ./zsh-plugins/* ~/.oh-my-zsh/custom/plugins/ #plug
sudo apt install zsh # shell
chsh -s /bin/zsh # chang default shell

echo 'configuration shell successful!!!'

# ? -> whatis command.
# sudo apt install cowsay
# cat 'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' >> ~/.bashrc
# cat 'alias ?=\'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)\'' >> ~/.bashrc

# sudo apt install cowsay
# cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1) # >> ~/.zshrc
# alias '?'='cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' # >> ~/.zshrc



