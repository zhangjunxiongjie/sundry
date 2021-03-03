
# config vim
sudo cp -r ./vim-runtime /opt/
sudo chmod a+x /opt/vim-runtime/install_awesome_parameterized.sh
sudo /opt/vim-runtime/install_awesome_parameterized.sh /opt/vim-runtime --all

# install 'oh my zsh' pulg manage of zsh.
# wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O ~/Downloads/ohmyzsh
#$(~/Downloads/ohmyzsh)

git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh #
cp ./zsh_config_file.txt ~/.zshrc # config
cp -r ./zsh-plugins/* ~/.oh-my-zsh/custom/plugins/ #plug
sudo apt install zsh # shell
chsh -s /bin/zsh # chang default shell


# ? -> whatis command.
# sudo apt install cowsay
# cat 'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' >> ~/.bashrc
# cat 'alias ?=\'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)\'' >> ~/.bashrc

# sudo apt install cowsay
# cat 'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)' >> ~/.zshrc
# cat 'alias ?=\'cowsay -f $(ls /usr/share/cowsay/cows | shuf -n 1 | cut -d. -f1) $(whatis $(ls /bin) 2>/dev/null | shuf -n 1)\'' >> ~/.zshrc



