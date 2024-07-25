vim.g.mapleader = " "
vim.g.maplocalleader = " "

local opt = { noremap = true, silent = true }

--##bufferline##
vim.keymap.set("n", "<C-h>", ":BufferLineCyclePrev<CR>", opt)
vim.keymap.set("n", "<C-l>", ":BufferLineCycleNext<CR>", opt)

--##nvim-tree##
vim.keymap.set("n", "<A-m>", ":NvimTreeToggle<CR>", opt) -- Open or close the tree
vim.keymap.set("n", "<A-n>", ":NvimTreeFocus<CR>", opt) -- focus on the tree
vim.keymap.set("n", "<A-f>", ":NvimTreeFindFile<CR>", opt)
vim.keymap.set("n", "<A-b>", ":NvimTreeCollapse<CR>", opt) -- 折叠

--##Telescop##
vim.keymap.set("n", "<C-p>", ":Telescope find_files<CR>", opt) -- 查找文件
vim.keymap.set("n", "<C-f>", ":Telescope live_grep<CR>", opt) -- 全局搜索


--## Use `[g` and `]g` to navigate diagnostics
--vim.keymap.set("s", "[g", ":coc-diagnostic-prev<CR>", opt)
--vim.keymap.set("s", "]g", ":coc-diagnostic-next<CR>", opt)
--## Remap keys for gotos
--vim.keymap.set("s", "gd", ":coc-definition<CR>", opt)
--vim.keymap.set("s", "gy", ":coc-type-definition<CR>", opt)
--vim.keymap.set("s", "gi", ":coc-implementation<CR>", opt)
--vim.keymap.set("s", "gr", ":coc-references<CR>", opt)

-- Use `[g` and `]g` to navigate diagnostics
-- Use `:CocDiagnostics` to get all diagnostics of current buffer in location list
vim.keymap.set("n", "[g", "<Plug>(coc-diagnostic-prev)", {silent = true})
vim.keymap.set("n", "]g", "<Plug>(coc-diagnostic-next)", {silent = true})

-- GoTo code navigation
vim.keymap.set("n", "gd", "<Plug>(coc-definition)", {silent = true})
vim.keymap.set("n", "gy", "<Plug>(coc-type-definition)", {silent = true})
vim.keymap.set("n", "gi", "<Plug>(coc-implementation)", {silent = true})
vim.keymap.set("n", "gr", "<Plug>(coc-references)", {silent = true})
