for /R %%s in (*.exe,*.ilk,*.obj,*.pdb,*.dat,*.txt) do (
	rm %%s
)