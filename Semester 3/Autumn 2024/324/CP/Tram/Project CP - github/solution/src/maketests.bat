@echo off
setlocal enabledelayedexpansion
goto :main

:main
setlocal

	
	for /L %%x in (1,1,10) do (
		prog.exe < input\in_case%%x > output\out_case%%x 
	)


endlocal
goto :eof
pause
