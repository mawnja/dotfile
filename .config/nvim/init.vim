
call plug#begin('~/.vim/plugged')

Plug 'Yggdroot/indentLine'
"Plug 'ervandew/supertab'
Plug 'crusoexia/vim-monokai'            "配色
Plug 'maxmx03/solarized.nvim'
Plug 'vim-airline/vim-airline'          "强大的状态栏和标签栏，当打开多个文本时，可以用它进行快速的切换，是一个很强大的工具
Plug 'vim-airline/vim-airline-themes'   "airline的主题
"Plug 'luochen1990/rainbow'
Plug 'preservim/nerdtree'               "树形的目录管理插件
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'majutsushi/tagbar'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'nvim-lua/plenary.nvim'
Plug 'nvim-telescope/telescope.nvim', {'tag': '0.1.6'}
Plug 'nvim-telescope/telescope-github.nvim'
Plug 'nvim-treesitter/nvim-treesitter'
Plug 'jacquesg/p5-Neovim-Ext'
Plug 'BurntSushi/ripgrep'
Plug 'sharkdp/fd'

call plug#end()

":CocInstall coc-clangd  # C++环境插件
":CocInstall coc-cmake  # Cmake 支持
":CocInstall coc-emmet  
":CocInstall coc-git    # git 支持
":CocInstall coc-highlight  # 高亮支持
":CocInstall coc-jedi   # jedi
":CocInstall coc-json   # json 文件支持
":CocInstall coc-python # python 环境支持
":CocInstall coc-sh     # bash 环境支持
":CocInstall coc-snippets # python提供 snippets
":CocInstall coc-vimlsp # lsp
":CocInstall coc-yaml   # yaml
":CocInstall coc-syntax
":CocInstall coc-pairs
"
"CocInfo
"CocConfig
"clangd.path: ~/.vim/plugged/coc_ext_install/clangd_install
"CocCommand clangd.install
"CocList extensions

"Note:
"coc-jedi，虚拟环境创建 需要先安装 sudo apt-get install python3.6-venv
"这样.venv创建才不会失败，@@@还有 coc-jedi与coc-python不兼容，不能同时安装@@@ Uninstall coc-python before using coc-jedi @@@
"还有coc-jedi需要python>3.6
"
"QS:
"coc/extensions/node_modules/coc-jedi/.env安装的jedi-language-server==0.37.0与~/.local/lib/python3.6/site-packages中jedi_language_server==0.35.1
"版本不一致，解决办法:coc/extensions/node_modules/coc-jedi/lib/index.js中修改版本号，package.js中修改版本号
"
":CocCommand python.setInterpreter "~/.local/bin/python3"

let g:python_version = 3.6
let g:python3_host_prog = '~/.local/bin/python3.6'
"
let g:loaded_perl_provider = 0
"let g:perl_host_prog = '/path/to/perl'

"indentLine可视化缩进
let g:indent_guides_guide_size  = 1     "指定对齐线的尺寸
let g:indent_guides_start_level = 2     "从第二层开始可视化显示缩进

" 设置状态栏
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline#extensions#tabline#buffer_nr_show = 0
let g:airline#extensions#tabline#formatairline#extensions#tabline#enabledter = 'default'
let g:airline_theme = 'dark'       "主题
let g:airline#extensions#keymap#enabled = 1
let g:airline#extensions#tabline#buffer_idx_mode = 1
let g:airline#extensions#tabline#buffer_idx_format = {
       \ '0': '0 ',
       \ '1': '1 ',
       \ '2': '2 ',
       \ '3': '3 ',
       \ '4': '4 ',
       \ '5': '5 ',
       \ '6': '6 ',
       \ '7': '7 ',
       \ '8': '8 ',
       \ '9': '9 '
       \}
" 设置切换tab的快捷键 <\> + <i> 切换到第i个 tab
nmap <leader>1 <Plug>AirlineSelectTab1
nmap <leader>2 <Plug>AirlineSelectTab2
nmap <leader>3 <Plug>AirlineSelectTab3
nmap <leader>4 <Plug>AirlineSelectTab4
nmap <leader>5 <Plug>AirlineSelectTab5
nmap <leader>6 <Plug>AirlineSelectTab6
nmap <leader>7 <Plug>AirlineSelectTab7
nmap <leader>8 <Plug>AirlineSelectTab8
nmap <leader>9 <Plug>AirlineSelectTab9
" 设置切换tab的快捷键 <\> + <-> 切换到前一个 tab
nmap <leader>- <Plug>AirlineSelectPrevTab
" 设置切换tab的快捷键 <\> + <+> 切换到后一个 tab
nmap <leader>+ <Plug>AirlineSelectNextTab
" 设置切换tab的快捷键 <\> + <q> 退出当前的 tab
nmap <leader>q :bp<cr>:bd #<cr>
" 修改了一些个人不喜欢的字符
if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif
let g:airline_symbols.linenr = "CL"     "current line
let g:airline_symbols.whitespace = '|'
let g:airline_symbols.maxlinenr = 'Ml'  "maxline
let g:airline_symbols.branch = 'BR'
let g:airline_symbols.readonly = "RO"
let g:airline_symbols.dirty = "DT"
let g:airline_symbols.crypt = "CR"
"nmap <tab> :bn<cr> "设置tab键映射"

" autocmd vimenter * NERDTree           "自动开启Nerdtree
let g:NERDTreeWinSize = 25              "设定 NERDTree 视窗大小
let NERDTreeShowBookmarks=1             "开启Nerdtree时自动显示Bookmarks
"打开vim时如果没有文件自动打开NERDTree
" autocmd vimenter * if !argc()|NERDTree|endif
"当NERDTree为剩下的唯一窗口时自动关闭
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
" 设置树的显示图标
let g:NERDTreeDirArrowExpandable = '+'
let g:NERDTreeDirArrowCollapsible = '-'
let NERDTreeIgnore = ['\.pyc$']          "过滤所有.pyc文件不显示
let g:NERDTreeShowLineNumbers=0          "是否显示行号
let g:NERDTreeHidden=0                   "不显示隐藏文件
""Making it prettier
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1
nnoremap <F3> :NERDTreeToggle<CR>        "开启/关闭nerdtree快捷键

" tagbar设置
let g:tagbar_width=30
nnoremap <silent> <F4> :TagbarToggle<CR> "将tagbar的开关按键设置为 F4


" coc.nvim
"
" if hidden is not set, TextEdit might fail.
set hidden
"Some servers have issues with backup files, see #649
set nobackup
set nowritebackup
 
" You will have bad experience for diagnostic messages when it's default 4000.
set updatetime=300
 
" don't give |ins-completion-menu| messages.
set shortmess+=c
 
" always show signcolumns
set signcolumn=yes
 
" Use tab for trigger completion with characters ahead and navigate.
" Use command ':verbose imap <tab>' to make sure tab is not mapped by other plugin.
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? "\<C-p>" : "\<C-h>"
 
function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction
 
" Use <c-space> to trigger completion.
inoremap <silent><expr> <c-space> coc#refresh()
 
" Use <cr> to confirm completion, `<C-g>u` means break undo chain at current position.
" Coc only does snippet and additional edit on confirm.
inoremap <expr> <cr> coc#pum#visible() ? "\<C-y>" : "\<C-g>u\<CR>"
" Or use `complete_info` if your vim support it, like:
" inoremap <expr> <cr> complete_info()["selected"] != "-1" ? "\<C-y>" : "\<C-g>u\<CR>"
 
" Use `[g` and `]g` to navigate diagnostics
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)
" Remap keys for gotos
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)
 
" Use K to show documentation in preview window
nnoremap <silent> K :call <SID>show_documentation()<CR>
 
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction
 
" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')
 
" Remap for rename current word
nmap <leader>rn <Plug>(coc-rename)
 
" Remap for format selected region
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)
 
augroup mygroup
  autocmd!
  " Setup formatexpr specified filetype(s).
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  " Update signature help on jump placeholder
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end
 
" Remap for do codeAction of selected region, ex: `<leader>aap` for current paragraph
xmap <leader>a  <Plug>(coc-codeaction-selected)
nmap <leader>a  <Plug>(coc-codeaction-selected)
 
" Remap for do codeAction of current line
nmap <leader>ac  <Plug>(coc-codeaction)
" Fix autofix problem of current line
nmap <leader>qf  <Plug>(coc-fix-current)
 
" Create mappings for function text object, requires document symbols feature of languageserver.
xmap if <Plug>(coc-funcobj-i)
xmap af <Plug>(coc-funcobj-a)
omap if <Plug>(coc-funcobj-i)
omap af <Plug>(coc-funcobj-a)
 
" Use `:Format` to format current buffer
command! -nargs=0 Format :call CocAction('format')
 
" Use `:Fold` to fold current buffer
command! -nargs=? Fold :call CocAction('fold', <f-args>)
 
" use `:OR` for organize import of current buffer
command! -nargs=0 OR :call CocAction('runCommand', 'editor.action.organizeImport')


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" telescope config
" Find files using Telescope command-line sugar.
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Using Lua functions
nnoremap <c-p> <cmd>lua require('telescope.builtin').find_files()<cr>
nnoremap <c-g> <cmd>lua require('telescope.builtin').live_grep()<cr>
nnoremap <c-b> <cmd>lua require('telescope.builtin').buffers()<cr>
nnoremap <c-h> <cmd>lua require('telescope.builtin').help_tags()<cr>

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" nvim的基本配置
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

filetype plugin on
" 设置为双字宽显示，否则无法完整显示如:☆
" set ambiwidth=double
set t_ut=               "防止vim背景颜色错误
set showmatch           "高亮匹配括号
set matchtime=1
set report=0
set ignorecase
"set nocompatible
set noeb
set softtabstop=4
set shiftwidth=4
set nobackup
set autoread
"set nocompatible
set nu                  "设置显示行号
set backspace=2         "能使用backspace回删
syntax on               "语法检测
set ruler               "显示最后一行的状态
set cursorline
set laststatus=2        "两行状态行+一行命令行
set ts=4
set expandtab
set autoindent          "设置c语言自动对齐
set t_Co=256            "指定配色方案为256
" set mouse=a           "设置可以在VIM使用鼠标
set selection=exclusive
" set selectmode=mouse,key
set tabstop=4           "设置TAB宽度
set history=1000        "设置历史记录条数   
" 配色方案
"let g:seoul256_background = 234
set background=light
"set background=dark
set shortmess=atl
colorscheme solarized
"colorscheme monokai
"colorscheme desert
"colorscheme morning
set guifont=Consolas:h17
"共享剪切板
set clipboard+=unnamed 
set cmdheight=3
if version >= 603
     set helplang=cn
     set encoding=utf-8
endif
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936
set fileencoding=utf-8
set updatetime=300
set shortmess+=c
set signcolumn=yes
 
" autocmd FileType json syntax match Comment +\/\/.\+$+
 
set foldmethod=indent    "设置默认折叠方式为缩进
set foldlevelstart=99    "每次打开文件时关闭折叠

" hi Normal ctermfg=252 ctermbg=none "背景透明
" au FileType gitcommit,gitrebase let g:gutentags_enabled=0
if has("autocmd")
    au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif
inoremap jj <Esc>        "将jj映射到Esc
