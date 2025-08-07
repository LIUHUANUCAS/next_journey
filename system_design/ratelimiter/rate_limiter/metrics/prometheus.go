package metrics

import "github.com/prometheus/client_golang/prometheus"

var (
	Allowed = prometheus.NewCounterVec(
		prometheus.CounterOpts{Name: "requests_allowed_total", Help: "Allowed requests"},
		[]string{"path"},
	)
	Denied = prometheus.NewCounterVec(
		prometheus.CounterOpts{Name: "requests_denied_total", Help: "Denied requests"},
		[]string{"path"},
	)
)

func Init() {
	prometheus.MustRegister(Allowed, Denied)
}
