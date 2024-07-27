local status, marks = pcall(require, "marks")
if not status then
	vim.notify("没有找到 marks")
	return
end
 
marks.setup({
    -- whether to map keybinds or not. default true
    default_mappings = true,
    -- which builtin marks to show. default {}
    builtin_marks = { ".", "<", ">", "^" },
    -- whether movements cycle back to the beginning/end of buffer. default true
    cyclic = true,
    -- whether the shada file is updated after modifying uppercase marks. default false
    force_write_shada = false,
    -- how often (in ms) to redraw signs/recompute mark positions. 
    -- higher values will have better performance but may cause visual lag, 
    -- while lower values may cause performance penalties. default 150.
    refresh_interval = 250,
    -- sign priorities for each type of mark - builtin marks, uppercase marks, lowercase
    -- marks, and bookmarks.
    -- can be either a table with all/none of the keys, or a single number, in which case
    -- the priority applies to all marks.
    -- default 10.
    sign_priority = { lower=10, upper=15, builtin=8, bookmark=20 },
    -- disables mark tracking for specific filetypes. default {}
    excluded_filetypes = {},
    -- disables mark tracking for specific buftypes. default {}
    excluded_buftypes = {},
    -- marks.nvim allows you to configure up to 10 bookmark groups, each with its own
    -- sign/virttext. Bookmarks can be used to group together positions and quickly move
    -- across multiple buffers. default sign is '!@#$%^&*()' (from 0 to 9), and
    -- default virt_text is "".
    bookmark_0 = {
        sign = "⚑",
        virt_text = "hello world",
        -- explicitly prompt for a virtual line annotation when setting a bookmark from this group.
        -- defaults to false.
        annotate = false,
    },
    mappings = {
        set = "m",            --#Sets a letter mark (will wait for input)
        set_next = "m,",
        toggle = "m;",        --#切换
        next = "m]",
        prev = "m[",
        delete = "dm",        --#Delete a letter mark (will wait for input)
        delete_line = "dm-",  --#Deletes all marks on current line.
        delete_buf = "dm<space>", --#Deletes all marks in current buffer.
        preview = "m:",
        set_bookmark0 = "m0"
        --prev = false          --#pass false to disable only this default mapping
    }
})