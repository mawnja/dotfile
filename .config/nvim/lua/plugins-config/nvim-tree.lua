local status, nvim_tree = pcall(require, "nvim-tree")
if not status then
	vim.notify("没有找到 nvim-tree")
	return
end

-- #FFFF00 黄色
-- #90EE90 浅绿色
-- #D2B48C 土黄色
--vim.cmd([[
--  hi NvimTreeNormal guibg=#333333
--]])

nvim_tree.setup({
    sort_by = "case_sensitive",
	-- 是否显示 git 状态
	git = {
		enable = false,
	},
	-- 过滤文件
	filters = {
		dotfiles = true, -- 过滤 dotfile
		custom = { "node_modules" }, -- 其他过滤目录
	},
    view = {
	    -- 文件浏览器展示位置，左侧：left, 右侧：right
	    side = "left",
	    -- 行号是否显示
	    number = false,
	    relativenumber = false,
	    signcolumn = "yes", -- 显示图标
	    width = 30,
    },
    renderer = {
        indent_markers = {
            enable = true,
        },
        icons = {
            glyphs = {
                folder = {
                    arrow_closed = '+',  -- 设置折叠目录的符号
                    arrow_open = '-',    -- 设置展开目录的符号
                },
            },
        },
        special_files = { "Cargo.toml", "Makefile", "README.md", "readme.md" },
        highlight_git = true,
        highlight_opened_files = "icon",
        root_folder_modifier = ":t",
        add_trailing = false,
        group_empty = false,
        full_name = false,
        highlight_modified = "none",
        highlight_bookmarks = "none",
        indent_width = 2,
        --padding = 1,
        symlink_destination = true,
    },
    update_focused_file = {
        enable = true, -- 启用焦点文件功能
        update_cwd = true, -- 当前文件焦点更新，则更新目录
    },
})
