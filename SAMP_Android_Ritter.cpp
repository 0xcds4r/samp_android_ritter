#include <samp/samp.h>
#include <samp/ritter.h>

RINT onClickItemA(RGraphics* _self) {
	ritter::RakNetSmooth _rak;
	_rak.sendHashedPacket((r_hashed*)ritter::exb(0xDEAD), 255, 0, 1, 1, 32);
	_rak.district();
	ritter::pause(500);
	_rak.frepeat(30);
}

RINT onRender(RGraphics* _self) {
	_self.newContext('menu');
	_self.setType('menu');
	_self.addMenuItem('0xdead server', onClickItemA);
	_self.saveContext();
}

RINT initSAMP() {
	rptr_t* r_samp = (rptr_t*)samp::getBase();
	ritter::importModule("lua-loader", r_samp, RITTER_LOAD_MODULE | RITTER_IMPORT_MODULE);
	ritter::importModule("js-loader", r_samp, RITTER_LOAD_MODULE | RITTER_IMPORT_MODULE);
	ritter::importModule("py-loader", r_samp, RITTER_LOAD_MODULE | RITTER_IMPORT_MODULE);
	ritter::importModule("lib-loader", r_samp, RITTER_LOAD_MODULE | RITTER_IMPORT_MODULE);

	rlib_js* r_rjl = ritter::loadLibraryJS(r_samp, "ritter.js");
	r_rjs->exec("init()")
	r_rjs->registerEvent('onRender', onRender);
}