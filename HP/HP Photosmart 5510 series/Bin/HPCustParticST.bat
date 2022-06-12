@echo off
::HPCustParticST.bat schedules (add) or removes (del) HPCustPartic.exe to/from the Windows Task Scheduler
::this file should only be called by the installer/uninstaller custom actions.
::
cd %2

if _%1_==_add_ (
 at 10:10 /interactive /every:1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 "\"%cd%\HPCustPartic.exe\" /UA %3 /DDV %4" > "%cd%\HPCustPartic1.dat"
 at 20:40 /interactive /every:1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 "\"%cd%\HPCustPartic.exe\" /UA %3 /DDV %4" > "%cd%\HPCustPartic2.dat"
 at %time% /interactive /every:1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 "\"%cd%\HPCustPartic.exe\" /UA %3 /DDV %4" > "%cd%\HPCustPartic3.dat"
 at 14:00 /interactive /every:1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 "\"%cd%\HPCustPartic.exe\" /UA %3 /DDV %4" > "%cd%\HPCustPartic4.dat"
 goto end
)

if _%1_==_del_ (
  for /f %%c in ('dir /b HPCustPartic*.dat') do (
   if exist "%cd%"\%%c (
    for /f "tokens=*" %%a in ('type "%cd%"\%%c') do call :do_at_del "%%a"
    del /f /q "%cd%\%%c"
    )
  )
 goto end
)

exit /b
:do_at_del
set sktempvar=%~1
for /d %%b in (%sktempvar%) do at %%b /delete /yes
exit /b


:end
exit 0