/**
*! In WSL Debian inside /ccextractor/linux when i write ./ccextractor -out=scc -nofc -dru /mnt/c/users/supra/ClonedProjects/CCExtractor/sccsupport.mov -o sccsupport.scc i get the subtitles on the screen but the last line reads 'No captions were found in input' and i get two output files -  sccsupport.scc which is empty and sccsupport.p0.svc01.scc which is also empty.

When I write ./ccextractor -out=scc -nofc -dru /mnt/c/users/supra/ClonedProjects/CCExtractor/sccsupport.mov -o sccsupport.srt i again see the subtitles on the screen but the last line reads 'No captions were found in input' and i get two output files -  sccsupport.srt which is empty and sccsupport.p0.svc01.scc which is also empty.

*? When I write ./ccextractor -out=srt -nofc -dru /mnt/c/users/supra/ClonedProjects/CCExtractor/sccsupport.mov -o sccsupport.srt i do not see the subtitles on the screen and the last line reads 'No captions were found in input' and i get two output files -  sccsupport.srt which is empty and sccsupport.p0.svc01.srt which contains the subtitles.
*/