


typedef struct {
  void (*func)(); // function to exec
  void *ctx; // context
} Defer;


// Runs the defer lofic
void run_defer(Defer *d) {
  if(d && d->func) {
    d->func(d->ctx);
  }
}
