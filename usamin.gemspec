# frozen_string_literal: true

lib = File.expand_path('lib', __dir__)
$:.unshift(lib) unless $:.include?(lib)
require 'usamin/js/version'

Gem::Specification.new do |spec|
  spec.name          = 'usamin-js'
  spec.version       = Usamin::Js::VERSION
  spec.authors       = ['Ishotihadus']
  spec.email         = ['hanachan.pao@gmail.com']

  spec.summary       = 'A RapidJSON-based JavaScript object generator for Ruby'
  spec.description   = 'A RapidJSON-based JavaScript object generator for Ruby.'
  spec.homepage      = 'https://github.com/Ishotihadus/usamin-js'
  spec.license       = 'MIT'

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.bindir        = 'exe'
  spec.executables   = spec.files.grep(%r{^exe/}) {|f| File.basename(f)}
  spec.require_paths = ['lib']
  spec.extensions    = ['ext/usamin_js/extconf.rb']

  spec.add_development_dependency 'bundler'
  spec.add_development_dependency 'pry'
  spec.add_development_dependency 'rake'
  spec.add_development_dependency 'rake-compiler'
  spec.add_development_dependency 'usamin'
end
