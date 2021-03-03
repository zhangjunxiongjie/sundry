


"花括号配置
"自动补全
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
:inoremap ( ()<ESC>i
:inoremap [ []<ESC>i
:inoremap { {}<ESC>i
:inoremap { {<CR>}<ESC>O

syntax on "自动语法高亮
set showmode
set showcmd
set mouse=a
set encoding=utf-8
set t_Co=256
filetype indent on
set textwidth=80
set wrap
set linebreak
set laststatus=2
set ruler
set showmatch
set hlsearch
set incsearch
set spell spelllang=en_us
set undofile

set backupdir=~/.vim/.backup//
set directory=~/.vim/.swp//
set undodir=~/.vim/.undo//

set visualbell

set wildmenu
set wildmode=longest:list,full

set history=10000
set number "显示行号

"ctermbg 背景色  ctermfg 前景色 guibg 下划线背景色  guifg 下划线前景色
set cursorline "突出显示当前行
"highlight Cursorline guibg = NONE guifg = NONE cterm = NONE ctermbg = NONE ctermfg = NONE
set cursorcolumn "突出显示当前列
"highlight CursorColumn cterm = NONE ctermbg = NONE ctermfg = NONE guibg = NONE guifg = NONE

set ruler "打开状态栏标尺

set tabstop=4 "tab设置为4
set expandtab "将tab转换为空格

set autoindent "自动缩进
set cindent

"统一缩进为4
set softtabstop=4
set shiftwidth=4

set expandtab "用空格替换制表符
set smarttab  "在行和段开始处使用制表符

"设置折叠
set foldenable "开始折叠
set foldmethod=syntax "设置语法折叠
set foldcolumn=0 "设置折叠区域的宽度
setlocal foldlevel=100 "设置折叠层数为100，默认不折叠
set foldclose=all "设置为自动关闭折叠 
nnoremap <space><space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR> 
"用空格键来开关折叠



